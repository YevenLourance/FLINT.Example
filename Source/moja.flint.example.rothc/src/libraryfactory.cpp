#include "moja/flint/example/rothc/libraryfactory.h"

// Modules
#include "moja/flint/example/rothc/plantresiduemodule.h"
#include "moja/flint/example/rothc/soilcovermodule.h"
#include "moja/flint/example/rothc/rothcmodule.h"

// Transforms

// Flint Data

// Providers

// Other

using moja::flint::IModule;
using moja::flint::ITransform;
using moja::flint::IFlintData;
using moja::flint::ModuleRegistration;
using moja::flint::TransformRegistration;
using moja::flint::FlintDataRegistration;
using moja::flint::FlintDataFactoryRegistration;
using moja::flint::DataRepositoryProviderRegistration;

namespace moja { namespace flint { namespace example { namespace rothc {

// Instance of common data structure

extern "C" {

	MOJA_LIB_API int getModuleRegistrations(ModuleRegistration* outModuleRegistrations) {
		int index = 0;
		outModuleRegistrations[index++] = ModuleRegistration{ "PlantResidueModule", []() -> flint::IModule* { return new PlantResidueModule(); } };
		outModuleRegistrations[index++] = ModuleRegistration{ "SoilCoverModule", []() -> flint::IModule* { return new SoilCoverModule(); } };
		outModuleRegistrations[index++] = ModuleRegistration{ "RothCModule", []() -> flint::IModule* { return new RothCModule(); } };
		return index;
	}

	MOJA_LIB_API int getTransformRegistrations(TransformRegistration* outTransformRegistrations) {
		int index = 0;
		//outTransformRegistrations[index++] = TransformRegistration{ "CompositeTransform",	[]() -> flint::ITransform* { return new CompositeTransform(); } };
		return index;
	}

	MOJA_LIB_API int getFlintDataRegistrations(FlintDataRegistration* outFlintDataRegistrations) {
		auto index = 0;
		//outFlintDataRegistrations[index++] = FlintDataRegistration{ "RunStatistics", []() -> flint::IFlintData* { return new RunStatistics(); } };
		return index;
	}

	MOJA_LIB_API int getFlintDataFactoryRegistrations(FlintDataFactoryRegistration* outFlintDataFactoryRegistrations) {
		auto index = 0;
		return index;
	}

	MOJA_LIB_API int getDataRepositoryProviderRegistrations(moja::flint::DataRepositoryProviderRegistration* outDataRepositoryProviderRegistration) {
		auto index = 0;
		//outDataRepositoryProviderRegistration[index++] = DataRepositoryProviderRegistration{ "RasterTiledBeast", static_cast<int>(datarepository::ProviderTypes::Raster), [](const DynamicObject& settings) ->std::shared_ptr<datarepository::IProviderInterface> { return std::make_shared<datarepository::ProviderSpatialRasterTiled>(std::make_shared<RasterReaderFactoryBeast>(), settings); } };
		return index;
	}

}

}}}} // moja::flint::example::rothc
